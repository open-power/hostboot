/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/test/hwpMBvpdAccessorTest.H $                    */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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

#ifndef __HWPMBVPDACCESSORTEST_H
#define __HWPMBVPDACCESSORTEST_H

// set to 1 for doing unit tests, set to 0 for production
#define HWPMBVPDACCESSORTEST_UT0 0 // 0 = just one chip, 1 = all
#define HWPMBVPDACCESSORTEST_UT1 0 // 0 = the last keword added, 1 = all & dump
#define HWPMBVPDACCESSORTEST_UT2 0 // 0 = min slope intercept tests
#define HWPMBVPDACCESSORTEST_UT3 0 // 0 = min L4 Bank Delete tests
#define HWPMBVPDACCESSORTEST_UT4 0 // 0 = min term data tests
#define HWPMBVPDACCESSORTEST_UT5 0 // 0 = min phase rotator data tests
#define HWPMBVPDACCESSORTEST_UT6 0 // 0 = include those moved in v5.3 redefine
#define HWPMBVPDACCESSORTEST_UT7 0 // 0 = min sensor map tests

/**
 *  @file hwpmbvpdaccessortest.H
 *
 *  @brief Test cases for MBvpd HWP accessors.
*/

#include <cxxtest/TestSuite.H>

#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>

#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

#include    <setMvpdRing.H>
#include    <mvpd_accessors/getMBvpdPhaseRotatorData.H>
#include    <mvpd_accessors/getMBvpdAddrMirrorData.H>
#include    <mvpd_accessors/getMBvpdTermData.H>
#include    <mvpd_accessors/getMBvpdSlopeInterceptData.H>
#include    <mvpd_accessors/getMBvpdVersion.H>
#include    <mvpd_accessors/getMBvpdDram2NModeEnabled.H>
#include    <mvpd_accessors/getMBvpdSensorMap.H>
#include    <mvpd_accessors/accessMBvpdL4BankDelete.H>

#include <errl/errlmanager.H>
#include <errl/errlentry.H>
#include <devicefw/driverif.H>
#include <trace/interface.H>


using namespace     fapi;
using   namespace   TARGETING;

class hwpMBvpdAccessorTest : public CxxTest::TestSuite
{
public:

    /**
     * @brief  call fapiGetMBvpdField to fetch memory buffer vpd records.
     *
     */
    void    testGetMBvpd()
    {
        fapi::ReturnCode    l_fapirc;
        uint8_t             *l_pRecord            =   NULL;
        uint32_t            l_len                =   0;

        // list of MBVPD records to test
        struct _testMBvpdRecords {
            fapi::MBvpdRecord record;
            fapi::MBvpdKeyword keyword;
        }  l_mbvpdRecords[] = {
#if HWPMBVPDACCESSORTEST_UT1
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
#endif
            { MBVPD_RECORD_VINI, MBVPD_KEYWORD_VZ},
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
#if HWPMBVPDACCESSORTEST_UT1
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
        fapi::ReturnCode    l_fapirc;
        getMBvpdSlopeInterceptData_FP_t (l_getMBvpdSlopeInterceptData)
                              = &getMBvpdSlopeInterceptData;
        uint32_t l_val = 0xFFFFFFFF;

        TS_TRACE( "testGetSlopeInterceptData entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetSlopeInterceptData l_memBufList.size()=%d",
                                      l_memBufList.size() );
        // loop thru memory buffers
#if HWPMBVPDACCESSORTEST_UT0
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
#if HWPMBVPDACCESSORTEST_UT2

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
#if HWPMBVPDACCESSORTEST_UT2
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
     * @brief call accessMBvpdL4BankDelete to fetch VSPD keyword MX
     *
     */
    void    testL4BankDelete()
    {
        fapi::ReturnCode    l_fapirc( fapi::FAPI_RC_SUCCESS );
#if HWPMBVPDACCESSORTEST_UT3
        accessMBvpdL4BankDelete_FP_t (l_accessMBvpdL4BankDelete)
                              = &accessMBvpdL4BankDelete;
#endif

        TS_TRACE( "testL4BankDelete entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testL4BankDelete l_memBufList.size()=%d",
                                      l_memBufList.size() );
        // loop thru memory buffers
#if HWPMBVPDACCESSORTEST_UT0
        uint8_t l_mbNum = 0;    // check them all in unit test
#else
        uint8_t l_mbNum = (l_memBufList.size() > 0) ? l_memBufList.size()-1 : 0;
#endif
        for (; l_mbNum < l_memBufList.size(); l_mbNum++ )
        {
            //  make a local copy of the memory buffer target
            TARGETING::Target*  l_mb_target = l_memBufList[l_mbNum];

            // cast OUR type of target to a FAPI type of target.
            fapi::Target l_fapi_mb_target( TARGET_TYPE_MEMBUF_CHIP,
                   (const_cast<TARGETING::Target*>(l_mb_target)) );

            // verify HWP accessor
            uint32_t l_val = 0xffffffff;

#if HWPMBVPDACCESSORTEST_UT3
            // Get
            l_fapirc=(*l_accessMBvpdL4BankDelete)(l_fapi_mb_target,
                         l_val,
                         GET_L4_BANK_DELETE_MODE);
            if (l_fapirc)
            {
               TS_FAIL( "fapiGetVersion: HWP accessor get fail rc=0x%x",
                     static_cast<uint32_t>(l_fapirc) );
               fapiLogError(l_fapirc);
            }
            else
            {
                TS_TRACE( "testL4BankDelete accessor get 0x%08x",l_val);
            }
            // Set (use same value)
            l_fapirc=(*l_accessMBvpdL4BankDelete)(l_fapi_mb_target,
                     l_val,
                     SET_L4_BANK_DELETE_MODE);
            if (l_fapirc)
            {
               TS_FAIL( "fapiL4BankDelete accessor set fail rc=0x%x",
                     static_cast<uint32_t>(l_fapirc) );
               fapiLogError(l_fapirc);
            }
#endif
            // verify attribute
            l_val = 0xffffffff;
            // Get
            l_fapirc = FAPI_ATTR_GET(ATTR_L4_BANK_DELETE_VPD,
                       &l_fapi_mb_target,
                       l_val);
            if (l_fapirc)
            {
               TS_FAIL( "fapiL4BankDelete: HWP attribute get fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
               fapiLogError(l_fapirc);
            }
            else
            {
                TS_TRACE( "testL4BankDelete attribute get 0x%08x",l_val);
            }
#if HWPMBVPDACCESSORTEST_UT3
            // Set (use same value)
            l_fapirc = FAPI_ATTR_SET(ATTR_L4_BANK_DELETE_VPD,
                       &l_fapi_mb_target,
                       l_val);
            if (l_fapirc)
            {
               TS_FAIL( "fapiL4BankDelete: HWP attribute set fail rc=0x%x",
                     static_cast<uint32_t>(l_fapirc) );
               fapiLogError(l_fapirc);
            }
#endif
        }

        TS_TRACE( "testL4BankDelete exit" );
     }

/**
     * @brief call getMBvpdSensorMap to fetch sensor map
     *        attributes from the MW keyword
     *
     */
    void    testGetSensorMap()
    {
        fapi::ReturnCode    l_fapirc;
        uint8_t l_val = 0xFF;

        TS_TRACE( "testGetSensorMap entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetSensorMap l_memBufList.size()=%d",
                                      l_memBufList.size() );
        // loop thru memory buffers
#if HWPMBVPDACCESSORTEST_UT0
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

#if HWPMBVPDACCESSORTEST_UT7
            // test accessor directly
            getMBvpdSensorMap_FP_t (l_getMBvpdSensorMap) = &getMBvpdSensorMap;

            // Primary Sensor Map
            l_fapirc = (*l_getMBvpdSensorMap)(l_fapi_mb_target,
                fapi::SENSOR_MAP_PRIMARY, l_val);
            if (l_fapirc) break;
                TS_TRACE( "testSensorMap accessor "
                "SENSOR_MAP_PRIMARY=0x%02x", l_val);

            // Secondary Sensor Map
            l_fapirc = (*l_getMBvpdSensorMap)(l_fapi_mb_target,
                fapi::SENSOR_MAP_SECONDARY, l_val);
            if (l_fapirc) break;
                TS_TRACE( "testSensorMap accessor "
                "SENSOR_MAP_SECONDARY=0x%02x", l_val);

            // test attribute
            // Primary Sensor Map
            l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CDIMM_SENSOR_MAP_PRIMARY,
                &l_fapi_mb_target, l_val);
            if (l_fapirc) break;
                TS_TRACE( "testSensorMap attr "
                "SENSOR_MAP_PRIMARY=0x%02x", l_val);
#endif

            // Secondary Sensor Map
            l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CDIMM_SENSOR_MAP_SECONDARY,
                &l_fapi_mb_target, l_val);
            if (l_fapirc) break;
                TS_TRACE( "testSensorMap attr "
                "SENSOR_MAP_SECONDARY=0x%02x", l_val);
        }

        if (l_fapirc)
        {
           TS_FAIL( "fapiGetSensorMap: FAPI_ATTR_GET fail rc=0x%x",
                 static_cast<uint32_t>(l_fapirc) );
           fapiLogError(l_fapirc);
        }

        TS_TRACE( "testGetSensorMap exit" );

    }

    /**
     * @brief call getMBvpdVersion to fetch vpd version
     *
     */
    void    testGetVersion()
    {
        fapi::ReturnCode    l_fapirc;
        getMBvpdVersion_FP_t (l_getMBvpdVersion)
                              = &getMBvpdVersion;

        TS_TRACE( "testGetVersion entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetVersion l_memBufList.size()=%d",
                                      l_memBufList.size() );
        // loop thru memory buffers
#if HWPMBVPDACCESSORTEST_UT0
        uint8_t l_mbNum = 0;    // check them all in unit test
#else
        uint8_t l_mbNum = (l_memBufList.size() > 0) ? l_memBufList.size()-1 : 0;
#endif
        for (; l_mbNum < l_memBufList.size(); l_mbNum++ )
        {
            TARGETING::TargetHandleList l_mbaList;
            getChildAffinityTargets(l_mbaList,l_memBufList[l_mbNum],
                            CLASS_UNIT,TYPE_MBA,false);

            TS_TRACE( "testGetVersion l_mbaBufList.size()=%d",
                    l_mbaList.size());

            // loop thru all the mbas (should be 2)
#if HWPMBVPDACCESSORTEST_UT0
            uint8_t l_mbaNum = 0;  // check them all in unit test
#else
            uint8_t l_mbaNum = (l_mbaList.size() > 0) ? l_mbaList.size()-1:0 ;
#endif
            for (; l_mbaNum < l_mbaList.size(); l_mbaNum++ )
            {
                TARGETING::TargetHandleList l_dimmList;

                getChildAffinityTargets(l_dimmList,l_mbaList[l_mbaNum],
                            CLASS_LOGICAL_CARD,TYPE_DIMM,false);
                TS_TRACE( "testGetVersion l_dimmList.size()=%d",
                    l_dimmList.size());

                // cast OUR type of target to a FAPI type of target.
                fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                      (const_cast<TARGETING::Target*>(l_mbaList[l_mbaNum])));

                // verify HWP accessor
                uint32_t l_val = 0xffffffff;

                l_fapirc = (*l_getMBvpdVersion)(l_fapi_mba_target,l_val);
                if (l_fapirc)
                {
                   TS_FAIL( "fapiGetVersion: HWP accessor fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
                   fapiLogError(l_fapirc);
                }
                else
                {
                    TS_TRACE( "testGetVersion accessor 0x%08x",l_val);
                }

                // loop thru all the DIMMs (should be 4)
#if HWPMBVPDACCESSORTEST_UT0
                uint8_t l_dimmNum = 0;  // check them all in unit test
#else
                uint8_t l_dimmNum =
                             (l_dimmList.size() > 0) ? l_dimmList.size()-1:0 ;
#endif
                for (; l_dimmNum < l_dimmList.size(); l_dimmNum++ )
                {
                    //  dump physical path to target
                    EntityPath l_path;
                    l_path = l_dimmList[l_dimmNum]->getAttr<ATTR_PHYS_PATH>();
                    l_path.dump();

                    // cast OUR type of target to a FAPI type of target.
                    fapi::Target l_fapi_dimm_target(
                                          TARGET_TYPE_DIMM,
                      (const_cast<TARGETING::Target*>(l_dimmList[l_dimmNum])));

                    // verify getting all attributes
                    l_fapirc = FAPI_ATTR_GET(ATTR_VPD_VERSION,
                           &l_fapi_dimm_target,
                           l_val);
                    TS_TRACE( "testGetVersion attribute %d 0x%08x",
                                   l_dimmNum,l_val);
                }
                if (l_fapirc)
                {
                   TS_FAIL( "fapiGetVersion: FAPI_ATTR_GET fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
                   fapiLogError(l_fapirc);
                }
            }
        }

        TS_TRACE( "testGetVersion exit" );

    }

    /**
     * @brief call getMBvpdDram2NModeEnabled to retrieve 2N mode
     *
     */
    void    testGetDram2NModeEnabled()
    {
        fapi::ReturnCode    l_fapirc;
        getMBvpdDram2NModeEnabled_FP_t (l_getMBvpdDram2NModeEnabled)
                              = &getMBvpdDram2NModeEnabled;

        TS_TRACE( "testGetDram2NModeEnabled entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetDram2NModeEnabled l_memBufList.size()=%d",
                                      l_memBufList.size() );
        // loop thru memory buffers
#if HWPMBVPDACCESSORTEST_UT0
        uint8_t l_mbNum = 0;    // check them all in unit test
#else
        uint8_t l_mbNum = (l_memBufList.size() > 0) ? l_memBufList.size()-1 : 0;
#endif
        for (; l_mbNum < l_memBufList.size(); l_mbNum++ )
        {
            TARGETING::TargetHandleList l_mbaList;
            getChildAffinityTargets(l_mbaList,l_memBufList[l_mbNum],
                            CLASS_UNIT,TYPE_MBA,false);

            TS_TRACE( "testGetDram2NModeEnabled l_mbaBufList.size()=%d",
                    l_mbaList.size());

            // loop thru all the mbas (should be 2)
#if HWPMBVPDACCESSORTEST_UT0
            uint8_t l_mbaNum = 0;  // check them all in unit test
#else
            uint8_t l_mbaNum = (l_mbaList.size() > 0) ? l_mbaList.size()-1:0 ;
#endif
            for (; l_mbaNum < l_mbaList.size(); l_mbaNum++ )
            {
                // cast OUR type of target to a FAPI type of target.
                fapi::Target l_fapi_mba_target( TARGET_TYPE_MBA_CHIPLET,
                      (const_cast<TARGETING::Target*>(l_mbaList[l_mbaNum])));

                // verify HWP accessor
                uint8_t l_val = 0xFF;

                l_fapirc = (*l_getMBvpdDram2NModeEnabled)
                                     (l_fapi_mba_target,l_val);
                if (l_fapirc)
                {
                   TS_FAIL("fapiGetDram2NModeEnabled:HWP accessor fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
                   fapiLogError(l_fapirc);
                }
                else
                {
                    TS_TRACE("testGetDram2NModeEnabled accessor 0x%02x",
                           l_val);
                }
                // verify attribute
                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_DRAM_2N_MODE_ENABLED,
                           &l_fapi_mba_target,
                           l_val);
                if (l_fapirc)
                {
                   TS_FAIL("fapiGetDram2NModeEnabled:"
                         " FAPI_ATTR_GET fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
                   fapiLogError(l_fapirc);
                }
                else
                {
                    TS_TRACE( "testGetDram2NModeEnabled attribute 0x%02x",
                           l_val);
                }
            }
        }

        TS_TRACE( "testGetDram2NModeEnabled exit" );

    }


    /**
     * @brief call getMBvpdAddrMirrorData to fetch memory buffer AM attributes
     *
     */
    void    testGetAddrMirrorData()
    {
        fapi::ReturnCode    l_fapirc;
        getMBvpdAddrMirrorData_FP_t (l_getMBvpdAddrMirrorData)
                              = &getMBvpdAddrMirrorData;

        TS_TRACE( "testGetAddrMirrorData entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetAddrMirrorData l_memBufList.size()=%d",
                                      l_memBufList.size() );
        // loop thru memory buffers
#if HWPMBVPDACCESSORTEST_UT0
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
#if HWPMBVPDACCESSORTEST_UT0
            uint8_t l_mbaNum = 0;  // check them all in unit test
#else
            uint8_t l_mbaNum = (l_mbaList.size() > 0) ? l_mbaList.size()-1:0 ;
#endif
            for (; l_mbaNum < l_mbaList.size(); l_mbaNum++ )
            {
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

                // verify attribute
                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_DRAM_ADDRESS_MIRRORING,
                           &l_fapi_mba_target,
                           l_val);
                if (l_fapirc)
                {
                   TS_FAIL( "fapiGetAddrMirrorData: FAPI_ATTR_GET fail rc=0x%x",
                         static_cast<uint32_t>(l_fapirc) );
                   fapiLogError(l_fapirc);
                }
                else
                {
                    TS_TRACE( "testGetAddrMirrorData attribute "
                           "(0x%02x,0x%02x),(0x%02x,0x%02x)",
                           l_val[0][0], l_val[0][1], l_val[1][0], l_val[1][1]);
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
        fapi::ReturnCode    l_fapirc;
        uint8_t val1[2][2] = {{0xFF,0xFF},{0xFF,0xFF}};
#if HWPMBVPDACCESSORTEST_UT4
        uint8_t val2[2][2][4]={
                              {{0xFF,0xFF,0xFF,0xFF},{0xFF,0xFF,0xFF,0xFF}},
                              {{0xFF,0xFF,0xFF,0xFF},{0xFF,0xFF,0xFF,0xFF}}};
        uint8_t l_errorChk = 1; //do error checks just once
        uint8_t  val4[2] = {0xFF,0xFF};
        uint32_t val3[2] = {0xFFFFFFFF,0xFFFFFFFF};
        uint8_t  val5[2] = {0xFF,0xFF};
#endif
        uint64_t val6    = 0xFFFFFFFFFFFFFFFF;

#if HWPMBVPDACCESSORTEST_UT4
        getMBvpdTermData_FP_t (l_getMBvpdTermData)
                              = &getMBvpdTermData;
#endif
        TS_TRACE( "testGetTermData entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetTermData l_memBufList.size()=%d",
                                      l_memBufList.size() );

        // loop thru memory buffers
#if HWPMBVPDACCESSORTEST_UT0
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
#if HWPMBVPDACCESSORTEST_UT0
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

#if HWPMBVPDACCESSORTEST_UT4
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
           // Verify fetching attributes using FAPI_ATTR_GET
           // TERM_DATA_DRAM_RON
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RON,
                   &l_fapi_mba_target, val1);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_DRAM_RON=(0x%02x,0x%02x),(0x%02x,0x%02x)",
                   val1[0][0], val1[0][1], val1[1][0], val1[1][1]);

#if HWPMBVPDACCESSORTEST_UT4
           // TERM_DATA_DRAM_RTT_NOM
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_NOM,
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
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_DRAM_RTT_WR,
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
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_ODT_RD,
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
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_ODT_WR,
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
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_RD_VREF,
                   &l_fapi_mba_target, val3);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_RD_VREF=0x%08x,0x%08x",
                   val3[0], val3[1]);

           // TERM_DATA_DRAM_WR_VREF
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_DRAM_WR_VREF,
                   &l_fapi_mba_target, val3);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_DRAM_WR_VREF=0x%08x,0x%08x",
                   val3[0], val3[1]);

           // TERM_DATA_DRAM_WRDDR4_VREF
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_DRAM_WRDDR4_VREF,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_DRAM_WRDDR4_VREF=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_RCV_IMP_DQ_DQS
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_RCV_IMP_DQ_DQS,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_RCV_IMP_DQ_DQS=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_DQ_DQS
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_DRV_IMP_DQ_DQS,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_DQ_DQS=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_CNTL
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_DRV_IMP_CNTL,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_CNTL=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_ADDR
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_DRV_IMP_ADDR,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_ADDR=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_CLK
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_DRV_IMP_CLK,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_CLK=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_DRV_IMP_SPCKE
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_DRV_IMP_SPCKE,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_DRV_IMP_SPCKE=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_DQ_DQS
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_SLEW_RATE_DQ_DQS,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_DQ_DQS=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_CNTL
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_SLEW_RATE_CNTL,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_CNTL=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_ADDR
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_SLEW_RATE_ADDR,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_ADDR=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_CLK
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_SLEW_RATE_CLK,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_CLK=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CEN_SLEW_RATE_SPCKE
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_SLEW_RATE_SPCKE,
                   &l_fapi_mba_target, val4);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CEN_SLEW_RATE_SPCKE=0x%02x,0x%02x",
                   val4[0], val4[1]);

           // TERM_DATA_CKE_PRI_MAP
               val3[0] = 0xFFFFFFFF;
               val3[1] = 0xFFFFFFFF;
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CKE_PRI_MAP,
                   &l_fapi_mba_target, val3);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CKE_PRI_MAP=0x%08x,0x%08x",
                   val3[0], val3[1]);
#endif

           // TERM_DATA_CKE_PWR_MAP
               val6 = 0xFFFFFFFFFFFFFFFF;
               l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CKE_PWR_MAP,
                   &l_fapi_mba_target, val6);
               if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_CKE_PWR_MAP=0x%016lx", val6);

#if HWPMBVPDACCESSORTEST_UT4
           // TERM_DATA_RLO
                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_RLO,
                   &l_fapi_mba_target, val5);
                if (l_fapirc) break;
               TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_VPD_RLO=(0x%02x,0x%02x)",
                   val5[0], val5[1]);

           // TERM_DATA_WLO
                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_WLO,
                   &l_fapi_mba_target, val5);
                if (l_fapirc) break;
                TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_VPD_WLO=(0x%02x,0x%02x)",
                   val5[0], val5[1]);

           // TERM_DATA_GPO
                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_GPO,
                   &l_fapi_mba_target, val5);
                if (l_fapirc) break;
                TS_TRACE( "testGetTermData attr "
                   "TERM_DATA_VPD_GPO=(0x%02x,0x%02x)",
                   val5[0], val5[1]);
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
     * @brief call getMBvpdPhaseRotData to fetch memory buffer MR attributes
     *
     */
    void    testGetPhaseRotatorData()
    {
        fapi::ReturnCode    l_fapirc;
        const uint8_t PORT_SIZE = 2;
        uint8_t l_attr_eff_cen_phase_rot[PORT_SIZE];

        TS_TRACE( "testGetPhaseRotatorData entry" );

        TARGETING::TargetHandleList l_memBufList;
        getAllChips(l_memBufList, TYPE_MEMBUF);

        TS_TRACE( "testGetPhaseRotatorData l_memBufList.size()=%d",
                                      l_memBufList.size() );

        // loop thru memory buffers
#if HWPMBVPDACCESSORTEST_UT0
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
#if HWPMBVPDACCESSORTEST_UT0
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

               // getting all the attributes is a bit of over kill.
               // cen_ddrphy.initfile accesses all the values
               // the exhaustive test is good for unit test
                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);
#if HWPMBVPDACCESSORTEST_UT5
                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CLK_P1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CLK_P1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A4=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A5=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A6=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A7=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A8=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A9=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A10=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A11=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A12=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A13=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A14=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_A15=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_BA2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_CASN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_RASN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_CMD_WEN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_PAR,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_PAR=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M_ACTN,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M_ACTN=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CKE3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_CSN3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M0_CNTL_ODT1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CKE3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN2=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_CSN3=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT0=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_CEN_PHASE_ROT_M1_CNTL_ODT1=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

#endif
#ifdef HWPMBVPDACCESSORTEST_UT6
                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_TSYS_ADR,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_TSYS_ADR=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);

                l_fapirc = FAPI_ATTR_GET(ATTR_VPD_TSYS_DP18,
                           &l_fapi_mba_target,
                           l_attr_eff_cen_phase_rot);
                if (l_fapirc) break;
                TS_TRACE( "testGetPhaseRotatorData"
                    " ATTR_VPD_TSYS_DP18=(0x%02x,0x%02x)",
                     l_attr_eff_cen_phase_rot[0],
                     l_attr_eff_cen_phase_rot[1]);
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

};  // end class

#endif
